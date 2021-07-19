print('''<html>
<body>
<table>''')
for i in range (1, 11):
    print('<tr>')
    for j in range (1, 11):
        print('<td>' + '<a href=http://' + str(i * j) + '.ru>' + str(i * j) + '</a> </td>')
    print('</tr>')
print('''</table>
</body>
</html>''')
