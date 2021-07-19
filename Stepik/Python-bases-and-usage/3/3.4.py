import xmltodict
import requests

url = 'https://stepik.org/media/attachments/lesson/245681/map2.osm'
fin = requests.get(url)


parsed_xml = xmltodict.parse(fin.content)

counter = 0


for smth in parsed_xml['osm']:
    #if not isinstance(parsed_xml['osm'][smth], list):
    #    smth = [smth]
        for smth_tag in parsed_xml['osm'][smth]:
            if 'tag' in smth_tag:
                tags = smth_tag['tag']
                if not isinstance(tags, list):
                    tags = [tags]
                for tag in tags:
                    if '@v' in tag and tag['@v'] == 'fuel':
                        counter += 1
print(counter)
