var ffi = require('ffi');

var autoencoder = ffi.Library('./x64/Dll/Autoencoder1', {
  'Test': [ 'double', [] ]
});

console.log(autoencoder.Test());