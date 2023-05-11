/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let initial = init;
    
    const increment = function() {
        return ++initial;
    };
    
    var reset = function() {
        return initial = init;
    };
    
    var decrement = function() {
        return --initial;
    }
    
    return {increment, reset, decrement};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */