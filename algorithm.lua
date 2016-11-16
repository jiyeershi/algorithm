local bubbleArr = {13, 12, 10, 8, 21, 12, 55, 12, 55, 100}

function printTab(Tag, arr)
	print(Tag)
	for i,v in ipairs(arr) do
		print(i,v)
	end
end

--[[冒泡排序:
1.设数组大小为n， n >２
2.分n-1轮比较，每一轮都是从第一个元素开始, 比较前后两个元素, 若要结果要为正序，将大的值进行往后放
3.每一轮得到当轮的最大值，即第一轮得到最大值，第二轮得到次大值...
]]
function bubbleSort(arr, largeFirst)
	assert(type(arr) == "table" and #arr > 2, "arr must be table, and count > 2")
	local count = #arr
	for i = 1, count - 1 do --总共count - 1轮比较
		for j = 1, count - i do --每轮比较count - i次
			if arr[j] < arr[j + 1] then
				local temp = arr[j + 1]
				arr[j + 1] = arr[j]
				arr[j] = temp
			end
		end
	end
end

-- printTab("before sort", bubbleArr)
-- bubbleSort(bubbleArr, true)
-- printTab("after sort", bubbleArr)

--[[
插入排序是一种简单直观的排序算法。它的工作原理非常类似于我们抓扑克牌
对于未排序数据(右手抓到的牌)，在已排序序列(左手已经排好序的手牌)中从后向前扫描，找到相应位置并插入。
插入排序在实现上，通常采用in-place排序（即只需用到O(1)的额外空间的排序），因而在从后向前扫描过程中，需要反复把已排序元素逐步向后挪位，为最新元素提供插入空间。
具体算法描述如下：
1.从第一个元素开始，该元素可以认为已经被排序
2.取出下一个元素，在已经排序的元素序列中从后向前扫描
3.如果该元素（已排序）大于新元素，将该元素移到下一位置
4.重复步骤3，直到找到已排序的元素小于或者等于新元素的位置
5.将新元素插入到该位置后
6.重复步骤2~5
]]
function insertSort(arr)
	assert(type(arr) == "table" and #arr > 2, "arr must be table, and count > 2")
	local count = #arr
	local ret = {}
	for i,v in ipairs(arr) do
		ret[i] = v
		arr[i] = 0
	end

	for i = 1, count do
		local findPos = i
		for j = i - 1, 1, -1 do
			if ret[i] > arr[j] then
				arr[j+1] = arr[j]
				findPos = j
			else
				break
			end
		end
		arr[findPos] = ret[i]
	end
end

-- printTab("before sort", bubbleArr)
-- insertSort(bubbleArr)
-- printTab("after sort", bubbleArr)

--[[
快排
]]
local times = 0
local Qsort
Qsort = function(arr, low, high)
	if low >= high then
		return
	end
	local first = low
	local last = high
	local key = arr[first]
	while first < last do
		print("first = ", first, "last = ", last)
		while (first < last and arr[last] >= key) do
			last = last - 1
		end
		print("a[last] = ", arr[last])
		local temp = arr[last]
		arr[last] = key
		arr[first] = temp
		print(unpack(arr))
		while (first < last and arr[first] <= key) do
			first = first + 1
		end
		print(arr[first])
		temp = arr[first]
		arr[first] = key
		arr[last] = temp
	end

	Qsort(arr, low, first)
	Qsort(arr, first, high)
	times = times + 1
	print("times = ", times)
end


local arr = {6, 1, 3, 7, 4, 7, 4, 9}
printTab("Qsort ...1", arr)
Qsort(arr, 1, #arr)
printTab("Qsort ...2", arr)

--[[
二分查找:
保证是正序序列，从小到大
]]
function bFind(arr, value)
	assert(type(arr) == "table", "arr must be table")
	local left = 1
	local right = #arr
	local searchTime = 0
	while true do
		searchTime = searchTime + 1
		if value < arr[left] or value > arr[right] then
			return false, nil, searchTime
		elseif value == arr[left] then
			return true, left, searchTime
		elseif value == arr[right] then
			return true, right, searchTime
		elseif (right - left == 1) then
			return false, nil, searchTime
		else
			local mid = math.floor((left + right) / 2)
			-- print("\n left = ", left, " right = ", right, " mid = ", mid, " midV = ", arr[mid])
			if value == arr[mid] then
				return true, mid, searchTime
			elseif value > arr[mid] then
				left = mid
			elseif value < arr[mid] then
				right = mid
			end
		end
	end
end

function bFind2(arr, value)
	local mid
    local low = 1
    local high = #arr
    while low <= high do
    	--[[注意这个地方会有小数取整，譬如low = 1, high = 2, 则mid为1，从而跳过了value与arr[2]的比较，
    	但上面的判断可以允许low == high，则又将这个损失给补了回来]]
        mid = math.floor((low + high) / 2)
        -- print("\n low = ", low, " high = ", high, " mid = ", mid, " midV = ", arr[mid]) 
        if value == arr[mid] then
            return mid
        elseif value < arr[mid] then
            high = mid - 1
        else
            low = mid + 1
        end
    end
    return 0
end

local test = {3, 5}
-- print(bFind(test, 4))
print(bFind2(test, 4))