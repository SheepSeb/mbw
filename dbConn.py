from rethinkdb import RethinkDB
r = RethinkDB()
r.connect( "localhost", 28015).repl()
cursor = r.db('mbw').table("id_microbit").run()
for document in cursor:
    print(document)