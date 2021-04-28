from rethinkdb import RethinkDB
r = RethinkDB()
r.connect( "localhost", 28015).repl()
r.db_create("mbw")
#r.db('mbw').table_create('id_microbit').run()