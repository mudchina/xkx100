// shandao3.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "山道");
        set("long", @LONG
此段山路是通往后山脚。往南上是一大片树林。往北下可以望见
一个较大的湖。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southup"   : __DIR__"shulin6",
                "northdown" : __DIR__"taiyi1",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/lingzhi" : random(2),
        ]));
	set("coor/x", -3190);
	set("coor/y", 170);
	set("coor/z", 90);
	setup();
        replace_program(ROOM);
}
