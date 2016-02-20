// gudi.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "谷底");
	set("long", @LONG
但听得耳边轰聋聋的响声越来越大，山崖也逐渐变得倾斜，而不再
象上面那么陡峭笔立了，终于到达谷底了。只见上面的上崖一条大瀑布
如玉龙悬空，滚滚而下，倾入了一座清澈异常的大湖之中。瀑布注入处
湖水翻滚，只离得瀑布十馀丈，湖水便一平如镜。
LONG );
	set("exits", ([
		"up" : __DIR__"yanfeng",
		"west" : __DIR__"hubian",
	]));
	set("outdoors", "wuliang" );
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", -21060);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}