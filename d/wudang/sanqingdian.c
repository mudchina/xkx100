// sanqingdian.c 三清殿
// Last Modified by winder on Aug. 18 2002

#include <ansi.h>
inherit ROOM;
int burnt, start_burn; 
int is_burning();
string look_an();


void create()
{
	set("short", "三清殿");
	set("long", @LONG
这里是凌霄宫的三清殿，是武当派会客的地点。供着元始天尊、太
上道君和天上老君的神像，香案(an)上香烟缭绕。靠墙放着几张太师椅，
地上放着几个蒲团。东西两侧是走廊，北边是练武的广场，南边是后院。
LONG );
	set("valid_startroom", 1);
	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"houyuan",
		"east"  : __DIR__"donglang1",
		"west"  : __DIR__"xilang",
	]));
	set("objects", ([
		CLASS_D("wudang") + "/guxu" : 1,
		CLASS_D("wudang") + "/song" : 1
	]));
	set("item_desc", ([
		"an" : (: look_an :),
	]));
//	set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -920);
	set("coor/z", 90);
	setup();
	burnt = 0;
	call_out("burn", 120, 1);
	"/clone/board/wudang_b"->foo();
}
/*
void init()
{
	object me;
	mapping skill_status;
	string *sname;
	int i, level;
	float exper;

	me = this_player();

	exper = to_float(me->query("combat_exp"));

	if ( !(skill_status = me->query_skills()) ) return;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++)
	{
		level = skill_status[sname[i]];
		if( pow(to_float(level), 3.0) / 10.0 > exper
		&& exper > 100.0
		&& sname[i] != "buddhism"
		&& sname[i] != "literate"
		&& sname[i] != "taoism" )
		{
			level = ceil( pow( exper*10.0, 0.333333) );
			me->set_skill(sname[i], level);
		}
	}
}
*/
void init()
{
	add_action("do_jing", "jing");
}

int is_buring()
{
	return (burnt < 3);
}	
string look_an()
{
	
	switch (burnt)
	{
		case 0:
			return(HIC"香案上供奉着新上的香火，芬芳满堂。\n"NOR);
			break;
		case 1:
			return(HIC"香案上香烟缭绕，香火烧得正旺。\n"NOR);
			break;
		case 2:
			return(HIC"香案上的香火已经烧了大半，几缕余烟，奄奄欲息。\n"NOR);
			break;
		default:
			return(HIY"香案上只剩下一堆烟灰，等着有人敬(jing)奉香火！！\n"NOR);
			break;
	}
}  // end of look_an

void burn(int phase)
{
	burnt = phase;
	
	if (burnt < 3) call_out("burn", 120, phase + 1);

} // end of burn

int do_jing(string arg)
{
	object obj, me;
	
	if( !objectp(me = this_player()) ) return 0;	
	if( !arg ) return notify_fail("你要敬什么？\n");  
	if( !objectp(obj = present(arg, me)) )
		return notify_fail("你身上没有这样东西。\n");
	if ( obj->query("id") != "incense" ||
		obj->is_character() ) return notify_fail("只能敬香！\n");  

	burnt = 0;
	remove_call_out("burn");
	call_out("burn", 120, 1);

	message_vision(HIC"$N拿出一"+obj->query("unit")+obj->query("name")+"，恭恭敬敬地插在香案上。\n"NOR, me);
		
	if (me->query("age") < 20 && me->query("wudang/offerring") < 60)
	me->add("wudang/offerring", 2);
	if (me->query("age") < 30 && me->query("wudang/offerring") < 120)
	me->add("wudang/offerring", 2);
	if (me->query("age") > 30 && me->query("wudang/offerring") < 150)
	me->add("wudang/offerring", 2);						 					      		

	destruct(obj);
	
	return 1;		
}

// End of File
