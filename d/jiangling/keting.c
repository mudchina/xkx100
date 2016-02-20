//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "客厅");
	set ("long", @LONG
这是知府大人接待宾客的地方，摆着茶几座椅，墙上还挂了几幅山
水条幅。茶几上新沏的一壶龙井还在冒着热气。
LONG);
	set("exits", ([
		"north" : __DIR__"huapu",
		"east"  : __DIR__"shanfang",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1488);
	set("coor/y", -2031);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}