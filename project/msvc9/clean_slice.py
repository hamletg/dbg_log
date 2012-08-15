import os,sys
from optparse import OptionParser
import shutil

g_cwd=os.getcwd()
g_options=None
g_args=None

def ProcessParam():
    global g_options
    global g_args

    parser = OptionParser()
    parser.add_option("-x","--debug", action="store_true", dest="m_debug", help="use debug executable")
    parser.add_option("","--dir", action="store_true", dest="m_tags", help="save the tags found")
    parser.add_option("","--wxon", action="store_true", dest="m_wx", help="use wxPython")
    parser.add_option("","--wxoff", action="store_false", dest="m_wx", help="don't use wxPython")
    parser.add_option("","--dir", dest="m_dir", help="give the input diretory", metavar="FILE")
    parser.add_option("","--out-dir", dest="m_out_dir", help="give the output diretory", metavar="FILE")
    parser.add_option("","--file-ext", dest="m_file_ext", action="store", type="string", help="set the extension to use for the ouput files")
    parser.add_option("-q", "--quiet", action="store_true", dest="verbose",help="don't print status messages to stdout")
    (options, args) = parser.parse_args(sys.argv)
    print "options=%s" %options
    print "args   =%s" %args
    
    g_options=options
    print "type of options = %s" % type(options)
    g_args=args
    argc=len(sys.argv)
    print "g_options.m_wx = %s" % g_options.m_wx
    if g_options.m_wx<>None:
        iswx=g_options.m_wx
    
class file_to_clean:
    def __init__(self,path=None):
        self.m_path=path
        self.m_fin=None
        self.m_fout=None
    def Clean(self,path=None):
        if path==None:
            path=self.m_path
            if path==None:
                return -1
        [p,f]=os.path.split(path)
        f_out=f+".backup"
        if (os.path.isfile(p+os.sep+f_out)==True):
            os.remove(p+os.sep+f_out)
        os.rename(path,p+os.sep+f_out)
        self.m_fin=open(p+os.sep+f_out)
        self.m_fout=open(path,"w")
        lines=self.m_fin.readlines()
        self.m_fin.close()
        rep_path=p.replace("\\","_").replace(":","_")
        for line in lines:
            l=line.replace(rep_path,"clean_slice_")
            self.m_fout.write(l)
        self.m_fout.close()
        print "rep_path = %s" % rep_path
        
        self.m_fout.close()
            
print "[clean_slice] file = %s" % sys.argv[1]

doit=file_to_clean(sys.argv[1])
doit.Clean()

   
