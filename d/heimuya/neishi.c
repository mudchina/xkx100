// Room: /d/heimuya/neishi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "小舍内室");
	set("long", @LONG
这里是小舍内室。收拾得精细异常。你一进去，就发现床沿坐着一
个打扮妖艳的人。那人也诧异地抬头，你发现他居然是个男人，手里执
着一枚绣花针！
LONG    );
	set("exits", ([
		"west" : __DIR__"xiaoshe",
	]));
	set("objects", ([
		CLASS_D("heimuya")+"/dongfang": 1,
	]));
	set("coor/x", -3240);
	set("coor/y", 4220);
	set("coor/z", 100);
	setup();
}
