import xmltodict
import requests

url = 'https://stepik.org/media/attachments/lesson/245571/map1.osm'

fin = requests.get(url)

parsedxml = xmltodict.parse(fin.content)
print(parsedxml['osm']['node'][100]['@id'])
