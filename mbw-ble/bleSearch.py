import pymongo
import asyncio
from bleak import discover
from datetime import date


myclient = pymongo.MongoClient("mongodb+srv://cristiana25:1qazse4rfvgy7@mbw.jttju.mongodb.net/mbw?ssl=true&ssl_cert_reqs=CERT_NONE")

mydb = myclient.mbw
pi = mydb.pi
print(mydb.list_collection_names())


def decrypt_rot13(message:str):
    decrypted = ""
    for i in range(len(message)):
        decrypted += chr(ord(message[i]) - 13)

    return decrypted





temp = 0
async def run():
    while True:
        devices = await discover()
        for d in devices:

            print(d)

            d.name = decrypt_rot13(d.name)
            #if d.name.startsWith("MB") and d.name[2:].isnumeric()  #uncomment for secure version
            if d.name.startswith("MB"):
               today = date.today()
               d1 = today.strftime("%d/%m/%Y")
               temp = eval(d.name[2:])
               mydb.pi.find_one_and_update({"id": str(d.address)},
               {"$set":
                   {"id":str(d.address),
                   "name":d.name,
                   "temperature":temp,
                   "date": str(d1)
                } }, upsert = True)


loop = asyncio.get_event_loop()
loop.run_until_complete(run())
