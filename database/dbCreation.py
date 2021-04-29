from rethinkdb import RethinkDB
rDB = RethinkDB()
host = "localhost"
port = 28015
rDB.connect( "localhost", 28015).repl()
rDB.db_create("mbw")
#r.db('mbw').table_create('id_microbit').run()