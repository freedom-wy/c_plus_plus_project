class CFoo(object):
    def __init__(self, val):
        print("CFoo����")
        self.m_n = val

    def __del__(self):
        print("CFoo����")


def test():
    cf1 = CFoo(1)
    del cf1
    return

    cf2 = CFoo(2)
    del cf2
    return


if __name__ == '__main__':
    test()
