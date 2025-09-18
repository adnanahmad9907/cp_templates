from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time
import os
import requests

MOODLE_URL = 'https://lms.iitmandi.ac.in/my/'
FILES_URL = 'https://lms.iitmandi.ac.in/user/files.php'

USERNAME = 'b23244'
PASSWORD = '7786957Adnan#'

def login(driver):
    driver.get(MOODLE_URL)
    time.sleep(3)
    driver.find_element(By.ID, 'username').send_keys(USERNAME)
    driver.find_element(By.ID, 'password').send_keys(PASSWORD)
    driver.find_element(By.ID, 'password').send_keys(Keys.RETURN)
    time.sleep(5)  # Wait for login to complete

def navigate_to_files(driver):
    driver.get(FILES_URL)
    time.sleep(5)  # Wait for files page to load

def check_for_input_file(driver):
    wait = WebDriverWait(driver, 15)
    
    # Wait for files container to load
    wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, "div.fp-content")))

    # Find all file elements
    files = driver.find_elements(By.CSS_SELECTOR, "div.fp-file.fp-hascontextmenu")
    
    input_file_div = None
    for f in files:
        filename = f.find_element(By.CSS_SELECTOR, "div.fp-filename").text.strip()
        if filename == "input.txt":
            input_file_div = f
            break
    
    if not input_file_div:
        print("input.txt not found.")
        return

    print("input.txt found!")

    # The href for the file is "#" (dummy), so instead download by simulating clicks:
    # Try to find download button inside context menu after clicking it
    
    # Open context menu
    context_button = input_file_div.find_element(By.CSS_SELECTOR, "a.fp-contextmenu")
    context_button.click()

    # Wait for download option to appear and click it
    download_button = wait.until(
        EC.element_to_be_clickable((By.CSS_SELECTOR, "a[title='Download']"))
    )
    download_button.click()

    # Switch to new tab opened by download (some moodle setups open files in new tab)
    time.sleep(3)
    if len(driver.window_handles) > 1:
        driver.switch_to.window(driver.window_handles[-1])
        current_url = driver.current_url
        cookies = {c['name']: c['value'] for c in driver.get_cookies()}

        # Download file content using requests to preserve cookies
        response = requests.get(current_url, cookies=cookies)
        if response.status_code == 200:
            content = response.text
            print("Downloaded file content:")
            print(content)
        else:
            print("Failed to download the file content")
            content = ""

        # Close the new tab and switch back
        driver.close()
        driver.switch_to.window(driver.window_handles[0])
    else:
        print("No new tab opened for download. Cannot fetch file content.")
        content = ""

    if not content:
        return

    # Delete the input.txt file now
    # Click context menu again (because it closed after clicking download)
    context_button = input_file_div.find_element(By.CSS_SELECTOR, "a.fp-contextmenu")
    context_button.click()

    # Wait for delete button and click
    delete_button = wait.until(
        EC.element_to_be_clickable((By.CSS_SELECTOR, "a[title='Delete']"))
    )
    delete_button.click()

    # Confirm the alert popup
    alert = wait.until(EC.alert_is_present())
    alert.accept()

    print("Deleted input.txt from Moodle.")

    # Process content via LLM (stub)
    output = process_with_llm(content)

    # Save output to output1.txt
    with open('output1.txt', 'w') as f:
        f.write(output)

    print("Saved output1.txt.")

    # Upload output1.txt back to Moodle
    upload_output_file(driver, 'output1.txt')

def process_with_llm(text):
    # Placeholder: replace this with your actual LLM API call or processing logic
    return f"Processed output:\n{text}"

def upload_output_file(driver, filepath):
    wait = WebDriverWait(driver, 15)

    # Click 'Add...' button to open upload dialog
    add_button = wait.until(EC.element_to_be_clickable((By.CSS_SELECTOR, "a[title='Add...']")))
    add_button.click()

    # Wait for file input element to appear (usually inside a modal iframe)
    file_input = wait.until(EC.presence_of_element_located((By.CSS_SELECTOR, "input[type='file']")))

    # Send file path to input element
    file_input.send_keys(os.path.abspath(filepath))

    # Wait for uploaded file to appear in the file list
    wait.until(EC.presence_of_element_located(
        (By.XPATH, f"//div[contains(@class,'fp-file')]//div[contains(text(), '{os.path.basename(filepath)}')]")
    ))

    # Click 'Save changes' button
    save_button = wait.until(EC.element_to_be_clickable((By.ID, "id_submitbutton_jPWQdB5YDuA24oh")))
    save_button.click()

    time.sleep(3)  # Let page reload or confirm upload
    print(f"Uploaded {filepath} to Moodle.")

def main():
    driver = webdriver.Chrome()
    try:
        login(driver)
        navigate_to_files(driver)
        while True:
            check_for_input_file(driver)
            print("Waiting 30 seconds before next check...")
            time.sleep(30)
    finally:
        driver.quit()

if __name__ == '__main__':
    main()
