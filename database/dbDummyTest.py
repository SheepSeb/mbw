from rethinkdb import RethinkDB
rDB = RethinkDB()
host = "localhost"
port = 28015
rDB.connect( host, port).repl()
rDB.db("mbw").table("id_microbit").insert([
    {
        'name':'MBW1',
        'temperature' : 30,
        'date': '10.5.2021',
    },
    {
        'name': 'MB2',
        'temperature' : 20,
        'date': '10.5.2021',
    },
    {
        'name': 'MB3',
        'temperature' : 10,
        'date': '10.5.2021',
    }
]).run()