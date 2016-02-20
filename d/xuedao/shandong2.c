// shandong2.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","洞口");
        set("long",@LONG
山谷里积雪被拢成几个雪堆，这里时常有人扫除积雪。你前面的峭
壁下隐隐约约有一个山洞。
LONG );
        set("exits",([
                "enter" : __DIR__"shandong3",
                "west"  : __DIR__"sroad9",
        ]));
        set("objects", ([
                CLASS_D("xueshan")+"/baoxiang" :1,
        ]));
        set("outdoors", "xueshan");
	set("coor/x", -109900);
	set("coor/y", -55000);
	set("coor/z", 300);
	setup();
        replace_program(ROOM);
}