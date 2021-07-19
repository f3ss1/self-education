import xmltodict
import requests

url = 'https://stepik.org/media/attachments/lesson/245678/map1.osm'
fin = requests.get(url)

counter_in = 0

parsed_xml = xmltodict.parse(fin.content)
counter_total = len(parsed_xml['osm']['node'])

for node in parsed_xml['osm']['node']:
    if 'tag' in node:
        counter_in += 1

print(counter_in, counter_total - counter_in)
