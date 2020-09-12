const {EventEmitter} = require('events');
const {createReadStream} = require('fs')
const eventEmitter = new EventEmitter();
// basic event emitter
// emit and on should be singleton i.e they should be of same instance
// the event emitters are execute synchronously in the current event loop
// an event can have multiple event listeners
// once method can be used for using a listener once
// adding and removing listeners
// eventNames -> for procuring the event names
let chunk = 0;
let file = createReadStream('./event_emitter.js')
file.on('open',()=>{
    console.log('started running');
})
file.on('close',()=>{
    console.log('completed reading');
})
file.on('data', (data)=>{
    console.log(++chunk+' ' +data);
})
eventEmitter.on('event',(data)=>{
    console.log('listener 1 fired '+data);
})
eventEmitter.on('event', (data) => {
    console.log('listener 2 fired '+data);
})
console.log('A');
eventEmitter.emit('event','B');
console.log('C');