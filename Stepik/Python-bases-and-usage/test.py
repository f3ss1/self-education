import re
MyStr = "<test>some text here</test> <other> more text </other> <test> even more text</test>"
print(re.findall("<test>(.*?)</test>", MyStr))
#print(re.sub(r'<.+?>', '', s))
