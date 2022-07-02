from getopt import *
import sys

def get_arguments():

    try:
        #option map
        options = getopt(sys.argv[1:],
                        shortopts="p:t:h",    
                        longopts=["path=", "time=", "help"])
    except GetoptError as e:
        print("ERROR, wrong option used: ", e)
        sys.exit(usage_collecter_usage())
    
    


    path = DEFAULT_CSV_PATH
    time = DEFAULT_TIME


    for (opts, args) in options[0]:  
        
        # Help options         
        if opts == "-h":
            sys.exit(usage_collecter_usage())
        elif opts == "--help":
            sys.exit(usage_collecter_usage())
        
        # Path Options
        if opts == '-p':
            path = args
        elif opts == '--path':
            path = args

        # Time Options
        try:            
            
            if opts == "-t":
                time = int(args)
            elif opts == "--time":
                time = int(args)

        except ValueError as e:
            print("ERROR, wrong value used MUST BE AN INT: ", e)
            sys.exit(usage_collecter_usage())
    
    return path, time

DEFAULT_CSV_PATH = "/home/usage.csv"
DEFAULT_TIME = 60
custom_p, custom_t = get_arguments()
print(custom_p, custom_t)
