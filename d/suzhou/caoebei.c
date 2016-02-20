// caoebei.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "曹娥碑");
	set("long",@long
相传曹娥死后葬于此，上虞令命邯郸淳作文镌碑(gravestone)以记
其事。时邯郸淳年方十三，文不加点，一挥而就，立于墓侧。
long);
	set("outdoors", "suzhou");
	set("exits",([
		"north" : __DIR__"jiangbian",
		"east"  : __DIR__"nongshe",
	]));
	set("no_clean_up", 0);
	set("item_desc", ([
		"gravestone" : "经过多年的风吹雨淋，碑上文字几不可考，倒是背面有“黄绢幼妇外孙齑臼”这么几个字。\n",
		"bei" : "经过多年的风吹雨淋，碑上文字几不可考，倒是背面有“黄绢幼妇外孙齑臼”这么几个字。\n",
	]) );
	set("coor/x", 770);
	set("coor/y", -1050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
