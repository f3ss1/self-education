import xmltodict
import requests

url = 'https://stepik.org/media/attachments/lesson/245681/map2.osm'
fin = requests.get(url)


parsed_xml = xmltodict.parse(fin.content)

counter = 0


for node in parsed_xml['osm']['node']:
    if 'tag' in node:
        tags = node['tag']
        if not isinstance(tags, list):
            tags = [tags]
        for tag in tags:
            if '@v' in tag and tag['@v'] == 'fuel':
                counter += 1
print(counter)
