print('''<html>
<body>
<table>''')
for i in range (1, 11):
    print('<tr>')
    for j in range (1, 11):
        print('<td>', i * j, '</td>')
    print('</tr>')
print('''</table>
</body>
</html>''')