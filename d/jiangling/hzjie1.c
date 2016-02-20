//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{
	set ("short", "汉正街");
	set ("long", @LONG
这是武汉最繁华的街道。从大江南北来的各色人等，熙熙攘攘，摩
肩接踵。西边是一家钱庄，可以听到叮叮当当的金银声音。东边是一
座酒楼，门额上悬挂一方横匾，“四季美”三字擦得闪闪发亮，阵阵酒
肉的香味传来。北边是条大驿道。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([
		"east" : __DIR__"sijimei",
		"west" : __DIR__"qianzhuang",
		"south": __DIR__"hzjie2",
		"north": __DIR__"yidao",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
