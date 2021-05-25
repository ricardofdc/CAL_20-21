# CAL_20-21

## Running and Compilation
* build and run using CLion

## App usage
* Choose map to load
* Choose algorithms to use
* Choose origin and destination nodes

## Testing other maps
* Go to: resources/Custom_Map/
* Substitute edges.txt and nodes.txt for new map
* Run application and choose to load 'custom map'

### nodes.txt file example
* number of nodes
* (id, x position, y position)
```
6
(1,1,2)
(2,2,3)
(3,2,6)
(4,5,4)
```


### edges.txt file example
* number of edges
* (origin node id, destination node id)
```
4
(1,2)
(2,4)
(4,3)
(3,1)
```