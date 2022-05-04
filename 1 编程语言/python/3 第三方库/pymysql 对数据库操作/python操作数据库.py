import pymysql
import json
import os

files = []
datas = []
for path, d, filelist in os.walk("material"):
    for filename in filelist:
        if ".json" in filename:
            files.append(filename)
for i in files:
    f = open("material/" + i)
    data = json.load(f)
    datas.append(data)
    print(data)
    f.close()

# 创建数据库表
# 创建数据库链接
db = pymysql.connect(host="localhost", user="root", passwd="root", database="testdb")
# 创建游标curso
cursor = db.cursor()
#sql代码
sql_creat = """
        create table if not EXISTS test(
            first_name varchar(20),
            last_name varchar(20),
            age int,
            sex varchar(10)
        )
        """
# 发送数据库操作execute
# cursor.execute(sql_creat)

# 插入数据
value = "('{0}', '{1}', {2}, '{3}')".format(datas[0]["first_name"], datas[0]["last_name"], datas[0]["age"], datas[0]["sex"])
sql_insert = """
            insert into test 
            (first_name, last_name, age, sex)
            values""" + value
cursor.execute(sql_insert)
db.commit()
# 查询数据
sql_select = """
            select * from test
        """
cursor.execute(sql_select)
result = cursor.fetchall()
for row in result:
    print(row)

db.close()
