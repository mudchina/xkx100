inherit ROOM;

void create()
{
        set("short", "大门");
        set("long",@LONG
天龙寺在大理城外点苍山中岳峰之北，正式寺名叫作崇圣寺，但大理
百姓叫惯了，都称之为“天龙寺”。天龙寺背负苍山，面临洱水，极占形
胜。寺有三塔，建于唐初，大者高二百余尺，十六级，塔顶有铁铸记云：
“大唐贞观尉迟敬德造。”相传天龙寺有五宝，三塔为五宝之首。
    你来到了天龙寺大门前，只见气势恢弘的两个大门柱上刻有一付对联
( duilian ) ，红漆覆字，颇有点拨众生之意。抬头上望，门楣上一块黑
木大匾，上题“崇圣寺”三个大字，笔意苍松。
LONG );
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"talin",
//                "north" : __DIR__"dadao4",
                "north" : "/d/dali/hongsheng",
        ]));
	set("item_desc",([
		"duilian" : "\n    心性无染本自圆成　但离妄缘即如如佛\n\n",
	]));	
        set("objects",([
                "/d/wudang/npc/guest" : 1,
        ]));
//        set("no_clean_up", 0);
	set("coor/x", -37000);
	set("coor/y", -57000);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}