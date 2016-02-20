// Room: /d/qilian/qitianfeng.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	set("short", "齐天峰");
	set("long", @LONG
北祈连山区第一高峰，直耸入云，无路可寻。只见山前竖着一块大
石 (stone)，据闻山中土人曾见时有黑衣神秘人出入此山，有胆大好奇
者入山探之，从未生还。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"eastdown" : __DIR__"zibaipo",
		"westdown" : __DIR__"tanglangling",
	]));
	set("objects", ([
		"/d/xingxiu/npc/trader" : 1,
	]));
	set("coor/x", -15000);
	set("coor/y", 3000);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}