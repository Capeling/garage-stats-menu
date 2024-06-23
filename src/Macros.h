#define LATE_MODIFY(method_name)\
static void onModify(auto& self) {\
    (void) self.setHookPriority(#method_name, INT_MIN);\
}

#define EARLY_MODIFY(method_name)\
static void onModify(auto& self) {\
    (void) self.setHookPriority(#method_name, INT_MAX - 1);\
}