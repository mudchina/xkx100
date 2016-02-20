// Room:  /d/luoyang/pingquan.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "平泉朝游");
	set("long",  @LONG
在洛阳城南三十里，龙门西边的山脚下，有个梁家屯村。这里山峦
环抱，林木掩映，泉水源口，清溪萦回，这就是唐武帝时宰相李德裕的
别墅。“平泉朝游”是洛阳大八景之一。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east" :  __DIR__"longmen1",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -510);
	set("coor/y", -45);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
