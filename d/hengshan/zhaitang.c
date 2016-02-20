// Last Modified by Sir on May. 22 2001
//Room: zhaitang.c 斋堂

inherit ROOM;
string* names = ({
	__DIR__"obj/mapo-doufu",
	__DIR__"obj/qingcai-fentiao",
	__DIR__"obj/culiu-baicai",
	__DIR__"obj/hongshao-qiezi",
});

void create()
{
	set("short","斋堂");
	set("long",@LONG
这里便是恒山白云庵的斋堂。斋堂里摆满了长长的餐桌和长凳，几
位小师太正来回忙碌着布置素斋。南边通向白云庵西廊。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"south" : __DIR__"byawest",
	]));

	set("objects",([
		__DIR__"obj/qingshui-hulu" : 1,
		names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,
		names[random(sizeof(names))]: 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 30);
	set("coor/y", 3220);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
