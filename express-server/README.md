# Express

## Installation
First time init the project
```
npm init
tsc --init
npm install -D typescript
npm install -D ts-node
npm install -D nodemon
```

Compile the typescript project by adding the following to package.json
```
"scripts":{
    "build" : "tsc --project ./",
}
```

Run the project by adding
```
"script":{
    "start":"nodemon src/index.ts",
}
```

## Usage

It starts on the 8000 port
```
npm start
```

## License
[GPL](https://choosealicense.com/licenses/gpl-3.0/)