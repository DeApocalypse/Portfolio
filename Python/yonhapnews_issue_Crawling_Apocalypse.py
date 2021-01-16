from bs4 import BeautifulSoup
from urllib.request import urlopen
response=urlopen('https://www.naver.com')
soup = BeautifulSoup(response, 'html.parser')
for v in soup.select('a.issue'):
    print(v.get_text())

f=open("CrawledIssues.txt","w")
for v in soup.select("a.issue"):
    f.write(v.get_text()+'\n\n')
f.close()
