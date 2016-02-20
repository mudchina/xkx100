// Room: /d/heimuya/baihutang.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
        set("short", "白虎堂");
        set("long",@LONG
这里是黑木崖的第二大堂“白虎堂”。堂内青砖铺地，堂内横尸满
地。
LONG );
        set("exits", ([
        	"north"   : __DIR__"baistep2",
        	"south"   : __DIR__"chitang", 
        ]));
        set("objects", ([
        	CLASS_D("heimuya")+"/shang" : 1,
        ]));       
//	set("no_clean_up", 0);
	set("coor/x", -3040);
	set("coor/y", 4000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}