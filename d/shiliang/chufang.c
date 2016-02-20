// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "厨房");
        set("long", @LONG
这里是温家的厨房，温家请的是很有名气的大师傅负责
打理全家的伙食，温家的师傅在全浙江都是很有名气的，这
时候还没到开饭时间，大师傅在那里坐着吸烟。
LONG
        );
        set("exits", ([
                "east" : __DIR__"zoulang3",                
        ]));
        set("objects", ([
                __DIR__"npc/dashifu" : 1,
        ]));
      
	set("coor/x", 1590);
	set("coor/y", -1920);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
 