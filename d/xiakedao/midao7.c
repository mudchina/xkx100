// midao7.c 密道

inherit ROOM;

void create()
{
        set("short", "秘密通道");
        set("long", @LONG
这是一个石室，地上和角落都是灰尘，大概好久没人来过了。在
石缝之间，长着几棵小草(cao) ，你仔细一看，原来它就是断肠蚀骨
腐心草。
LONG );
       set("exits", ([
               "east"    : __DIR__"midao6",
               "out"     : __DIR__"dating",
               "northup" : __DIR__"midao8",
       ]));
       set("objects", ([
               "/clone/medicine/vegetable/fuxincao" : 1,
       ]));
	set("coor/x", -3090);
	set("coor/y", -25000);
	set("coor/z", -20);
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="out")
            tell_object(me,"你走出了秘密通道，神秘地出现在大厅之中。\n");
        return ::valid_leave(me,dir);
}