select C.Cid, C.Cname, count(E.Sid) students
from Course C
join Enroll E on C.Cid = E.Cid
group by C.Cid, C.Cname
having count(E.Sid) = (
    select max(students)
    from (
        select count(Sid) students
        from Enroll
        group by Cid
    ) T
);


select C.Cid, C.Cname, count(E.Sid) students
from Course C
join Enroll E on C.Cid = E.Cid
group by C.Cid, C.Cname
having count(E.Sid) = (
    select min(students)
    from (
        select count(Sid) students
        from Enroll
        group by Cid
    ) T
);


select Instructor, count(Cid) courses
from Course C
group by Instructor
having count(Cid) = (
    select max(courses)
    from (
        select count(Cid) courses
        from Course
        group by Instructor
    ) Ins
);


select C.Cid, C.Cname,
avg(
    case
        when Grade = 'A' then 90
        when Grade = 'B' then 80
        when Grade = 'C' then 70
    end
) AvgGrade
from Course C
join Enroll E on C.Cid = E.Cid
group by C.Cid, C.Cname
having AvgGrade = (
    select max(AvgGrade)
    from (
        select avg(
            case
                when Grade = 'A' then 90
                when Grade = 'B' then 80
                when Grade = 'C' then 70
            end
        ) AvgGrade
        from Enroll
        group by Cid
    ) T
);


select C.Cid, C.Cname,
avg(
    case
        when Grade = 'A' then 90
        when Grade = 'B' then 80
        when Grade = 'C' then 70
    end
) AvgGrade
from Course C
join Enroll E on C.Cid = E.Cid
group by C.Cid, C.Cname
having AvgGrade = (
    select min(AvgGrade)
    from (
        select avg(
            case
                when Grade = 'A' then 90
                when Grade = 'B' then 80
                when Grade = 'C' then 70
            end
        ) AvgGrade
        from Enroll
        group by Cid
    ) T
);


select S.Sid, S.Sname,
avg(
    case
        when Grade = 'A' then 90
        when Grade = 'B' then 80
        when Grade = 'C' then 70
    end
) AvgGrade
from Student S
join Enroll E on S.Sid = E.Sid
group by S.Sid, S.Sname
having AvgGrade > (
    select avg(
        case
            when Grade = 'A' then 90
            when Grade = 'B' then 80
            when Grade = 'C' then 70
        end
    )
    from Enroll
);


select C.Cid, C.Cname, count(E.Sid) StudentCount
from Course C
join Enroll E on C.Cid = E.Cid
group by C.Cid, C.Cname
having count(E.Sid) > (
    select avg(StudentCount)
    from (
        select count(Sid) StudentCount
        from Enroll
        group by Cid
    ) T
);

