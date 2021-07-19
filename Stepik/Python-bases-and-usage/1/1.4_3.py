from urllib.request import urlopen
from bs4 import BeautifulSoup

url = 'https://stepik.org/media/attachments/lesson/209723/5.html'
html = urlopen(url)
soup = BeautifulSoup(html, 'html.parser')
prepared = soup.findAll('td')
total = 0
for item in prepared:
    total += int(item.get_text())
print(total)
