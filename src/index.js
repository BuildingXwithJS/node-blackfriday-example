try {
  module.exports = require('../build/Release/addon.node');
} catch (err) {
  module.exports = require('../build/Debug/addon.node');
}
