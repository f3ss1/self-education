from urllib.request import urlopen
import re
url = "https://stepik.org/media/attachments/lesson/209719/2.html"
html = urlopen(url).read().decode('utf-8')
word_list = re.findall("<code>(.*?)</code>", html)
word_counter = {}
for word in word_list:
    if word in word_counter:
        word_counter[word] += 1
    else:
        word_counter[word] = 1
sorted_counter = sorted(word_counter, key=word_counter.get, reverse=True)
biggest = word_counter[sorted_counter[0]]
for i in range(len(sorted_counter)):
    if word_counter[sorted_counter[i]] < biggest:
        break
print(i)
print(word_counter['try'])
