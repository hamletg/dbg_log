

#ifndef LOGICEDBGCTRLIF_ICE
#define LOGICEDBGCTRLIF_ICE

module logicedbg
{

    interface sqlitectrl
    {
		void SetDbName(string s,bool inmem);
        void Enable(bool val);
    };

};

#endif
