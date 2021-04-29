from rethinkdb import RethinkDB
rDB = RethinkDB()
host = "localhost"
port = 28015
rDB.connect( host, port).repl()
cursor = rDB.db('mbw').table("id_microbit").run()
for document in cursor:
    print(document)