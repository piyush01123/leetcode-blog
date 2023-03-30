class MyCalendar:

    def __init__(self):
        self.bookings = []

    def book(self, start: int, end: int) -> bool:
        end -= 1
        for (s,e) in self.bookings:
            if s<=start<=e or s<=end<=e or (start<s and end>e):
                return False
        self.bookings.append((start,end))
        return True
        


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)