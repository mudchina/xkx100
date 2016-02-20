// Room: /d/yueyang/fengshanyin.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "封山印");
	set("long", @LONG
在龙口东侧、二妃墓西侧的临湖岸边上，原有四颗秦始皇的封山印
(yin) ，如今仅存其二。相传秦始皇六合一统后南巡潇湘，在洞庭湖留
印封山，欲伏风浪。如今碧山仍在，绿树长青，君临天下的始皇帝呢，
唯留荒冢。史浪荡涤，沧海桑田，慷慨如是。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("item_desc", ([
		"yin" : "
    始皇帝南巡乘船至此附近突然湖风浊浪，船不能行进，便问左右：
“此乃何地？”侍臣回报：“此地名君山，湘君女神之的所在，故作此
患。”始皇帝听后大怒曰：“岂有君之理？”侍臣劝其上山拜求湘君，
求湘水神宁波息浪，始皇帝恃其万乘之威，不肯求拜，反令刑徒三千伐
尽其树，放火烧山毁尽其庙宇、亭台，并以九龙镶金的玉玺，对准岩石
用力盖去，留印封山，意欲使湘水女神不再为患。不意洞庭湖仍湖风大
作，波浪滔天，船只被阻隔在君山。始皇帝始知无奈湘水神何，终致登
山求拜，风浪而后息，船只始得畅通。\n"
	]));
	set("exits", ([
		"northwest" : __DIR__"xiaolu1",
		"northeast" : __DIR__"xiaolu3",
	]));
	set("coor/x", -1700);
	set("coor/y", 2270);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
