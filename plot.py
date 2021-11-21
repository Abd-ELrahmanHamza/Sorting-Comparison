import matplotlib.pyplot as plt
import math
x = [1000, 5000, 10000, 50000, 75000, 100000, 500000]
selection1 = [2, 52, 205, 5086, 11608, 20650, 20650]
insertion1 = [2, 38, 155, 3859, 8694, 15256, 15256]
merge1 = [0, 2, 5, 31, 47, 63, 356]
quick1 = [0, 0, 1, 12, 18, 26, 147]
hybrid1 = [0, 0, 2, 11, 17, 25, 136]

selection = [math.log10(x) if x!=0 else x for x in selection1]
insertion = [math.log10(x) if x != 0 else x for x in insertion1]
merge = [math.log10(x) if x != 0 else x for x in merge1]
quick = [math.log10(x) if x != 0 else x for x in quick1]
hybrid = [math.log10(x) if x != 0 else x for x in hybrid1]
print(selection)
print(insertion)
print(merge)
print(quick)
print(hybrid)
# plot lines
plt.plot(x, selection, label="Selection")
plt.plot(x, insertion, label="Insertion")
plt.plot(x, merge, label="Merge")
plt.plot(x, quick, label="Quick")
plt.plot(x, hybrid, label="Hybrid")
plt.xlabel("Size of input")
plt.ylabel("log10 of Running time(Milliseconds)")
plt.title("Random data")
plt.legend()

plt.show()


selectionSorted1 = [2,56,205,5215,11549,20485,20485]
insertionSorted1 = [0,0,0,0,0,0,4]
mergeSorted1 = [0,2,4,30,44,58,297]
quickSorted1 = [0,0,1,9,14,20,116]
hybridSorted1 = [0,0,1,6,9,15,85]
selectionSorted = [math.log10(x) if x != 0 else x for x in selectionSorted1]
insertionSorted = [math.log10(x) if x != 0 else x for x in insertionSorted1]
mergeSorted = [math.log10(x) if x != 0 else x for x in mergeSorted1]
quickSorted = [math.log10(x) if x != 0 else x for x in quickSorted1]
hybridSorted = [math.log10(x) if x != 0 else x for x in hybridSorted1]
print(selectionSorted)
print(insertionSorted)
print(mergeSorted)
print(quickSorted)
print(hybridSorted)
# plot lines
plt.plot(x, selectionSorted, label="Selection")
plt.plot(x, insertionSorted, label="Insertion")
plt.plot(x, mergeSorted, label="Merge")
plt.plot(x, quickSorted, label="Quick")
plt.plot(x, hybridSorted, label="Hybrid")
plt.xlabel("Size of input")
plt.ylabel("log10 of Running time(Milliseconds)")
plt.title("Sorted data")
plt.legend()
plt.show()
