// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html

class PeekingIterator implements Iterator<Integer> {
		boolean hasVal = false;
	int val = 0;
	Iterator < Integer > iterator;
	public PeekingIterator(Iterator < Integer > iterator) {
	    this.iterator = iterator;
	}
	public Integer peek() {
	    if (hasVal) return val;
	    else val = iterator.next();
	    hasVal = true;
	    return val;
	}
	@Override
	public Integer next() {
	    if (hasVal) {
	        hasVal = false;
	        return val;
	    } else return iterator.next();
	}

	@Override
	public boolean hasNext() {
	    return hasVal || iterator.hasNext();
	}
}