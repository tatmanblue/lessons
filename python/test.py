from getopt import GetoptError, getopt
from re import A
import sys


#Help page // Displays how to use the script
def usage_collecter_usage():
    print("""Usage: resource-monitor.py 

    OPTIONS:
    -p or --path        : Optional, Used to designate path loaction for the .csv file.
                          resource-monitor.py -p /desired/path/location
                          resource-monitor.py --path /desired/path/location

    -t or --time        : Optional, Used to designate time interval at which data is collected for the .csv file. (In seconds)
                          resource-monitor.py -t 10   
                          resource-monitor.py --time 10                   

    -h or --help        : Optional, Shows all options and how to use them.
    """)

def get_arguments():

    try:
        #option map
        options = getopt(sys.argv[1:],
                        shortopts="p:t:h",    
                        longopts=["path=", "time=", "help"])
    except GetoptError as e:
        print("ERROR, wrong option used: ", e)
        sys.exit(usage_collecter_usage())
   
    if not options[0]:
        path = DEFAULT_CSV_PATH
        time = DEFAULT_TIME
    elif options:
        for (opts, args) in options[0]:  
            
            # Help options         
            if opts == "-h":
                sys.exit(usage_collecter_usage())
            elif opts == "--help":
                sys.exit(usage_collecter_usage())
            
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

global DEFAULT_CSV_PATH
global DEFAULT_TIME
DEFAULT_CSV_PATH = "/home/usage.csv"
DEFAULT_TIME = 60
beef, corn = get_arguments()
print(beef, corn)
