import axios from 'axios';

const url = '/api/devices';

class DeviceService{
    static getDevices(){
        return new Promise((resolve,reject) =>{
            axios.get(url).then((res)=>{
                const data = res.data;
                resolve(data);
            }).catch((err) =>{
                reject(err);
            })
        })
    }
}

export default DeviceService;