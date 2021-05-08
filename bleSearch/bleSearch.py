import pymongo
import asyncio
from bleak import discover
from datetime import date


myclient = pymongo.MongoClient("mongodb+srv://cristiana25:1qazse4rfvgy7@mbw.jttju.mongodb.net/mbw?ssl=true&ssl_cert_reqs=CERT_NONE")

mydb = myclient.mbw
pi = mydb.pi
print(mydb.list_collection_names())


async def run():
    while True:
        devices = await discover()
        for d in devices:
            print(d)
            if d.name.startswith("MB"):
               today = date.today()
               d1 = today.strftime("%d/%m/%Y")
               mydb.pi.find_one_and_update({"id": str(d.address)}, 
               {"$set":
                   {"id":str(d.address),
                   "name":d.name,
                   "temperature":int(d.name[2:]),
                   "date": str(d1)
                } }, upsert = True)


loop = asyncio.get_event_loop()
loop.run_until_complete(run())