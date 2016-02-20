// /quest/quest.h
// Modified by Zeratul Jan 5 2001

mapping quest_name = ([
		"wei"	:	"收罗物品",
		"book"	:	"查找秘籍",
		"shan"	:	"锄奸杀邪",
		"helian":	"一品堂",
		"betrayer":	"斩杀叛徒",
		"thief"	:	"捉捕奸细",
		"baobiao":	"护送人质",
		"bt"	:	"扬州捕快",
		"kill" : "江湖仇杀",
]);

void quest_finished( object who, string quest_type )

{
	string quest = "quest/" + quest_type;
	
	if ( !who->query_temp( quest ) )
		who->set_temp( quest, 1 );
	else
	{
		who->add_temp( quest, 1 );
		if ( who->query_temp( quest ) >= 1 + random(3) )
			for ( int i = 0; i < sizeof(quest_name); i++ )
				if ( who->query( "quest/" + keys(quest_name)[i] + "/lock" ) == quest_type )
				{
					who->delete( "quest/" + keys(quest_name)[i] + "/lock" );
					tell_object( who, "你可以领取"HIG + values(quest_name)[i] + NOR"任务了！\n"NOR );
					who->set( "quest/" + keys(quest_name)[i] + "/finished", 1 );
				}
	}
	who->set( quest + "/finished", 1 );
}

void quest_failed( object who, string quest_type )
{
	object obj;
	
	who->delete_temp( "quest/" + quest_type );
	who->delete( "quest/" + quest_type + "/finished" );
	if ( objectp( obj = who->query( "quest/" + quest_type + "/obj" ) ) )
		destruct( obj );
}

void lock_quest( object who, string quest_type, string lock_type )
{
	
	quest_failed( who, quest_type );
	who->set( "quest/" + quest_type + "/lock", lock_type );
	who->delete_temp( "quest/" + lock_type );			
}

int islocked( object who, string quest_type )
{
	string lock_quest = who->query( "quest/" + quest_type + "/lock" );
	object me = this_object();
	
	if ( stringp(lock_quest) && lock_quest != "" )
	{
		tell_object( who, "你得先完成"HIY + quest_name[lock_quest] + NOR"任务才能继续这个任务。\n" );
		return 1;
	}
	return 0;
}
