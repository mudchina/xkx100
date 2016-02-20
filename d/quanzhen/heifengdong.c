// heifengdong.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "黑凤洞");
        set("long", @LONG
此处位於终南山脉东部的太阳山上。只见山峰直上直下，像刀切
般的陡峭，只山腰上有一个碾盘子粗的石洞，不时冒出一股黑气，怪
可怕的。往西是一片树林。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "westup"  : __DIR__"shulin3",
        ]));

	set("coor/x", -3160);
	set("coor/y", 80);
	set("coor/z", 80);
	setup();
        replace_program(ROOM);
}
